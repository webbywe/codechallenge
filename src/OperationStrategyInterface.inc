<?php

/**
 * @file
 * Contains OperationStrategy.
 */

namespace webbywe;

/**
 * Interface OperationStrategy.
 *
 * @package webbywe
 */
interface OperationStrategyInterface {
  /**
   * Static function to return a solution.
   *
   * @param array $arguments
   *   An array of arguments.
   *
   * @return mixed
   *   A solution to be returned.
   */
  public static function solution(array $arguments);

}
