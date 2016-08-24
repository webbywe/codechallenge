<?php namespace webbywe;

/**
 * @file
 * Contains Http.
 */

use Drush\Make\Parser\ParserYaml;
use GuzzleHttp\Client;
use Symfony\Component\Yaml\Exception\ParseException;
use Symfony\Component\Yaml\Yaml;

/**
 * Class Http
 * @package webbywe
 */
class Http {

  /**
   * Take the XML and turn it into an standardized array.
   *
   * @param \SimpleXMLElement $xml
   *   A simpleXML element.
   *
   * @return array
   *   A standardized array.
   */
  private static function xmlToArray(\SimpleXMLElement $xml) {
    $data = [];

    foreach ($xml as $key => $value) {
      if ($key == 'arguments') {
        foreach ($value as $item_value) {
          $data['arguments'][] = (string) $item_value;
        }

        continue;
      }

      $data[$key] = (string) $value;
    }

    return $data;
  }

  /**
   * Send the request to fetch the Challenge API URI.
   *
   * @param $endpoint
   *   An endpoint from the API (minus the URI)
   *
   * @return array|bool
   *   A standardized array.
   */
  public static function send($endpoint) {
    $endpoint = self::buildURI($endpoint);

    $response = (new Client())->get($endpoint);

    if ($response->getStatusCode() != 200) {
      return FALSE;
    }

    $type = current(explode(';', $response->getHeader('Content-Type')));
    switch ($type) {
      case 'text/xml':
        $xml = $response->xml();
        $data = self::xmlToArray($xml);
        break;

      case 'application/json':
        $data = $response->json();
        break;

      case 'text/yaml':
        $data = Yaml::parse($response->getBody());
        break;

      default:
        drupal_set_message(t('There was an error processing @endpoint. No content-type for @type', array(
          '@endpoint' => $endpoint,
          '@type' => $type,
        )), 'error');

        drupal_exit();
    }

    return $data;
  }

  public static function buildURI($endpoint, $solution = '') {
    // Replace the solution token with solution if set.
    if (!empty($solution)) {
      $endpoint = str_replace('{your solution}', $solution, $endpoint);
    }

    // Replace the auth in the $endpoint.
    $endpoint = str_replace('auth=', 'auth=' .CHALLENGE_AUTH, $endpoint);

    return CHALLENGE_URI . $endpoint;
  }
}
