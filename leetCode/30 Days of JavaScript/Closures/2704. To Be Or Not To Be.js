/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val)
{

    return {toBe : (n) = > {
                               if (val == = n){
                                   return true;
}
else
{
    throw Error("Not Equal");
}
}
,
    notToBe : (n) = >
{
    if (val != = n)
    {
        return true;
    }
    else
    {
        throw Error("Equal");
    }
}
}
;
}
;

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */