<?php

/**
 * @file
 * Contains AdditionOperation.
 */

namespace webbywe;

/**
 * Class AdditionOperation.
 *
 * @package webbywe
 */
class AdditionOperation implements OperationStrategyInterface {

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
    $solution = 0;

    foreach ($arguments as $number) {
      $solution += $number;
    }

    return $solution;
  }

}
