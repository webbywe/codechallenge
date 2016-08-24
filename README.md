# Challenge #

This module navigates through a series of API calls answering 
each challenge request.

The module uses Guzzle 5.0 for API calls and conversion of XML and JSON responses. 
For responses that are returned in YAML, the symfony/yaml package is used. 
Although this module utilizes packages, this module is overall lightweight
due to auto-loading of the classes.
 
## Installation ##
 
 1. Add the following to the settings.php file.
  
    This will create the vendor and composer.json one directory
    above the Drupal installation root. Placing at the Drupal root will
    throw an alert in running the Security Audit module.
    
    Change to `./` vs. `../` to place composer.json in Drupal installation.
    
    ```
    $conf['composer_manager_vendor_dir'] = '../vendor';
    $conf['composer_manager_file_dir'] = '../';
    ```
 1. Copy `composer.json.inc` to `composer.json` one directory above Drupal root.
 
    If `composer.json` already exists, run the following where located:
    
        composer require guzzlehttp/guzzle:5.x
        composer require symfony/yaml
  
 1. Run `composer install` where `composer.json` is located.
 
 1. Download and enable `composer_manager` contrib module.
 
 1. At command prompt, run `drush composer-json-rebuild` at Drupal root.
 
 1. Download and enable this module to `/sites/all/modules/custom/challenge/` directory.
 
 1. Navigate to `http://{domain}/challenge`