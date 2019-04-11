# wyreg: fast randomized large scale linear regression
```
Y=XB		//the conventional regression setting
W=Guassian	//random projection matrix
Z=XW	        //project X to low dimension
Y=ZA		//solve the low dimension regression
Y=XWA => B=WA	//get the regression coefficients back
```

explaination: this model can be think as a single hidden layer neural network with linear activation:

X->Z->Y
      
