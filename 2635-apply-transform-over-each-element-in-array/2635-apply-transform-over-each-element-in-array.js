/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    var updatedArr = [];
    for(var i = 0; i < arr.length ; i++){
        updatedArr[i] = fn(arr[i], i);
    }
    return updatedArr;
    
};