let n = 10;
let arr = new Array(n);
for(i=0; i<arr.length; i++){
    arr[i] = new Array(n);
}

let k = 1;
for(i=0; i<arr.length; i++){
    for(j=0; j<arr.length; j++){
        arr[i][j] = k;
        k++;
    }
}

for(i=0; i<arr.length; i++){
    for(j=0; j<arr.length;j++){
        if(i!==j){
            arr[i][j] = " - "
        }
    }
    console.log(arr[i].join(' '));
}