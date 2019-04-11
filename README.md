# wyreg: fast randomized large scale linear regression
```
Y=XB		//the conventional regression setting
W=Guassian	//random projection matrix
z=XW	        //project X to low dimension
Y=zb		//solve the low dimension regression
Y=XWb => B=Wb	//get the regression coefficients back
```

explaination: this model can be think as a single hidden layer neural network with linear activation:

XXXXXXXXXXXXXX
 \\\\\|//////
    zzzzz
     \|/
      Y
      
