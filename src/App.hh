<?hh // strict

namespace Test\Strategy;

use Test\Strategy\Contract\Context;

/**
 * Main application class.
 *
 * @since     v0.1.0
 * @version   v1.0.0
 * @package   Test\Strategy
 * @author    Francisco Briones
 */
class App
{
    /**
     * The application context.
     *
     * @var mixed[null|Test\Strategy\Contract\Context]
     */
    private ?Context $context;
    
    /**
     * The associated instance.
     *
     * @var mixed[null|Test\Strategy\App]
     */
    private static ?App $instance;
    
    /**
     * Generates a new app instance.
     * 
     * @return void
     */
    private function __construct()
    {
    
    }

    /**
     * Get a instance of this class as a singleton.
     * 
     * @return Test\Strategy\App
     */
    public static function getInstance() : App
    {
        if (self::$instance === null) {
            self::$instance = new App();
        }
        return self::$instance;
    }

    /**
     * Start the app.
     * 
     * @return void
     */
    public function start() : void
    {
        $this->print('Hi, this is a bundle to test dessing patterns');
        $this->print('lets start with strategy pattern, please provide me with a propper context');
        $this->evaluate();
        $this->getContext()->notify();
    }

    /**
     * Get a option from the user.
     * 
     * @return void
     */
    private function getOption() : string
    {
        $this->print('the options are:');
        $this->print('a');
        $this->print('b');
        $this->print('c');
        $option = \readline('');
        $this->print('ok, the option selected is '. $option);
        return $option;
    }

    /**
     * Get the associated Context.
     * 
     * @return Test\Strategy\Contract\Context
     */
    private function getContext() : Context
    {
        if ($this->context === null) {
            throw new \Exception("hey, there wasn't any context provided.. quitting");
        }
        return $this->context;
    }

    /**
     * Set the current context.
     *
     * @param Test\Strategy\Contract\Context $context
     * 
     * @return void
     */
    private function setContext(Context $context) : void
    {
        $this->context = $context;
    }

    /**
     * Print something with a line jump.
     *
     * @param string
     * 
     * @return void
     */
    public function print(string $message) : void
    {
        \print_r($message);
        \print_r("\n");
    }

    /**
     * Evaluate the given option.
     * 
     * @return void
     */
    private function evaluate() : void
    {
        $ctx = $this->getOption();

        $classname = "Test\\Strategy\\Context\\Context".\strtoupper($ctx);

        if ( ! \class_exists($classname)) {
            $this->print('The given context is invalid :((');
            $this->evaluate();
        }

        $reflection = new \ReflectionClass(
            "Test\\Strategy\\Context\\Context".\strtoupper($ctx)
        );
            
        $this->setContext($reflection->newInstanceArgs([$this]));
    }
}