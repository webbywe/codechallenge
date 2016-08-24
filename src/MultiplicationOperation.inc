<?php

/**
 * @file
 * Contains MultiplicationOperation.
 */

namespace webbywe;

/**
 * Class MultiplicationOperation.
 *
 * @package webbywe
 */
class MultiplicationOperation implements OperationStrategyInterface {

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
    $solution = 1;

    foreach ($arguments as $number) {
      $solution = (int) $number * $solution;
    }

    return $solution;
  }

}
