/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn)
{

    var new_arr = [];
    for (var i = 0; i < arr.length; i++)
    {

        if (fn(arr[i], i))
        {
            new_arr.push(arr[i]);
        }
    }

    return new_arr;
};