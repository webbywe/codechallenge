<?php

/**
 * @file
 * Contains DateAdditionOperation.
 */

namespace webbywe;

/**
 * Class DateAdditionOperation.
 *
 * @package webbywe
 */
class DateAdditionOperation implements OperationStrategyInterface {
  /**
   * Process the solution based on arguments.
   *
   * @param array $arguments
   *   An array of arguments.
   *
   * @return int
   *   The processed solution.
   */
  public static function solution(array $arguments) {
    $date_string = $arguments[0];
    $span = $arguments[1];

    $date = new \DateTime($date_string);
    $date->modify('+ ' . $span);

    return $date->getTimestamp();
  }

}
