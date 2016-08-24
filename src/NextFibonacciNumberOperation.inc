<?php namespace webbywe;

/**
 * @file
 * Contains NextFibonacciNumberOperation.
 */

/**
 * Class NextFibonacciNumberOperation
 * @package webbywe
 */
class NextFibonacciNumberOperation implements OperationStrategy {

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
    // Get the last two numbers for the arguments.
    $last_two = array_slice($arguments, -2, 2);

    return (int) $last_two[0] + (int) $last_two[1];
  }
}

