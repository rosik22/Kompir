let namedFunc = function iter(arr) { // Named function declared by expression
    if(Array.isArray(arr)) for(let elem of arr) iter(elem);
    else console.log(arr);
    console.log(arr + ": " +typeof(arr));
};

namedFunc('0-0', '0-1');