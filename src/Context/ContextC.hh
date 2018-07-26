<?hh // strict

namespace Test\Strategy\Context;

use Test\Strategy\Contract\Context;
use Test\Strategy\App;

/**
 * A context implementation.
 *
 * @since     v0.1.0
 * @version   v1.0.0
 * @package   Test\Strategy\Context
 * @author    Francisco Briones
 */
class ContextC implements Context
{
    /**
     * The associated context.
     *
     * @const string
     */
    const string CONTEXTNAME = 'context c';

    
    /**
     * Get a new context instance.
     *
     * @param Test\Strategy\App $app the caller app
     */
    public function __construct(private App $app)
    {
        
    }

    /**
     * Get the given app.
     * 
     * @return Test\Strategy\App
     */
    public function getApp() : App
    {
        return $this->app;
    }

    /**
     * Get the associated context name.
     * 
     * @return void
     */
    public function getContextName() : string
    {
        return self::CONTEXTNAME;
    }

    /**
     * Notify the user of the current implementation.
     * 
     * @return void
     */
    public function notify() : void
    {
        $this->getApp()->print('the current context is '.$this->getContextName());
    }
}