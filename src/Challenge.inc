<?php namespace webbywe;

/**
 * @file
 * Contains Challenge.
 */

/**
 * Class Challenge
 * @package webbywe
 */
class Challenge {
  /**
   * Return a string in a class case so auto-loader can find it.
   *
   * @param $string
   *   The operation string (ex. next_fibonacci_number).
   *
   * @return mixed
   *   Return a string formatted (ex. NextFibonacciNumber).
   */
  public static function toClassCase($string) {
    return str_replace(' ', '', ucwords(str_replace('_', ' ', trim($string))));
  }

  /**
   * Get the solution based on arguments supplied for an operation key.
   *
   * @param string $operation
   *   The operation to perform (ex. next_fibonacci_number)
   * @param array $arguments
   *   An array of arguments.
   *
   * @return mixed
   *   Return the calculated solution
   */
  public static function solution($operation, Array $arguments) {
    $class_name = 'webbywe\\' . self::toClassCase($operation) . 'Operation';

    return (class_exists($class_name)) ? (new $class_name())::solution($arguments) : FALSE;
  }
}