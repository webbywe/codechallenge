<?php

/**
 * @file
 * Contains NextFibonacciNumberOperation.
 */

namespace webbywe;

/**
 * Class NextFibonacciNumberOperation.
 *
 * @package webbywe
 */
class NextFibonacciNumberOperation implements OperationStrategyInterface {

  /**
   * Process the solution based on arguments.
   *
   * @param array $arguments
   *   An array of arguments.
   *
   * @return int|mixed
   *   The processed solution.
   */
  public static function solution(array $arguments) {
    // Get the last two numbers for the arguments.
    $last_two = array_slice($arguments, -2, 2);

    return (int) $last_two[0] + (int) $last_two[1];
  }

}
