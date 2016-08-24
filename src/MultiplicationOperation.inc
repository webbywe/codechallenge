<?php namespace webbywe;

/**
 * @file
 * Contains MultiplicationOperation.
 */

/**
 * Class MultiplicationOperation
 * @package webbywe
 */
class MultiplicationOperation implements OperationStrategy {

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
    $solution = 1;

    foreach ($arguments as $number) {
      $solution = (int) $number * $solution;
    }

    return $solution;
  }
}

