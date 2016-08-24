<?php namespace webbywe;

/**
 * @file
 * Contains DateAdditionOperation.
 */

/**
 * Class DateAdditionOperation
 * @package webbywe
 */
class DateAdditionOperation implements OperationStrategy {

  /**
   * Process the solution based on arguments.
   *
   * @param array $arguments
   *   An array of arguments.
   *
   * @return int|mixed
   *  The processed solution.
   */
  public static function solution(Array $arguments) {
    $date_string = $arguments[0];
    $span = $arguments[1];

    $date = new \DateTime($date_string);
    $date->modify('+ ' . $span);

    return $date->getTimestamp();
  }
}