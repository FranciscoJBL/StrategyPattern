<?hh 

namespace Test\Public;

use Test\Strategy\App;

require dirname(__DIR__) . DIRECTORY_SEPARATOR . 'vendor' . DIRECTORY_SEPARATOR . 'autoload.php';

$app = App::getInstance();
$app->start();