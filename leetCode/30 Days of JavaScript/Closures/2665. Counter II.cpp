/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init)
{

    var counter = init;
    return
    {
    increment:
        () = >
        {
            return ++counter;
        }
        ,
            reset : () = >
        {
            return counter = init;
        }
        ,
            decrement : () = >
        {
            return --counter;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */