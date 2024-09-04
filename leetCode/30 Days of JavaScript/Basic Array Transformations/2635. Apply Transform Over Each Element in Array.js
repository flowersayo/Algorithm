/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

// 1. Using a for loop with operational container
var map = function(arr, fn)
{

    let new_arr = [];
    for (let i = 0; i < arr.length; i++)
    {

        new_arr.push(fn(arr[i], i));
        // new_arr.push(fn.call(this, arr[i], i))
    }

    return new_arr;
};

// 2. Using a for loop without any container a.k.a Inmemory transformations
// bad practice as it alters the given data and also It can result in unexpected problems
var map = function(arr, fn)
{
    for (let i = 0; i < arr.length; ++i)
    {
        arr[i] = fn(arr[i], i);
    }
    return arr;
};

// 3. Using the forEach method
var map = function(arr, fn)
{
    const transformedArr = [];
    arr.forEach((element, index) = > {
        transformedArr[index] = fn(element, index);
    });
    return transformedArr;
};

// 4. Using the reduce method

var map = function(arr, fn)
{
    return arr.reduce((transformedArr, element, index) = > {
        transformedArr[index] = fn(element, index);
        return transformedArr;
    },
                      []);
};

// 5. Using the for...of loop

var map = function(arr, fn)
{
    const transformedArr = [];
    let index = 0;
    for (const element of arr)
    {
        transformedArr[index] = fn(element, index);
        index++;
    }
    return transformedArr;
};
