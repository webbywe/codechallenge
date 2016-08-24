<?php namespace webbywe;

/**
 * @file
 * Contains AdditionOperation.
 */

/**
 * Class AdditionOperation
 * @package webbywe
 */
class AdditionOperation implements OperationStrategy {

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
    $solution = 0;

    foreach ($arguments as $number) {
      $solution += $number;
    }

    return $solution;
  }
}

