function fibonacci(num){    
    if(num === 1) 
        return 0; 
    if (num === 2) 
        return 1; 
    return fibonacci(num - 1) + fibonacci(num - 2); 
} 
for (let i=7; i<17; i++){
    console.log("fibonacci("+ (i-1) + "): " +fibonacci(i)+"\n");
}