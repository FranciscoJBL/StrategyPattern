<?hh // strict

namespace Test\Strategy\Contract;

/**
 * A context representation.
 *
 * @since     v0.1.0
 * @version   v1.0.0
 * @package   Test\Strategy\Contract
 * @author    Francisco Briones
 */
interface Context
{
    /**
     * Notify the user of the current implementation.
     * 
     * @return void
     */
    public function notify() : void;
}