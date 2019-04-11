# wyreg: fast randomized large scale linear regression
```
Y=XB		//the conventional regression setting
W=Guassian	//random projection matrix
Z=XW	        //project X to low dimension
Y=ZA		//solve the low dimension regression
Y=XWA => B=WA	//get the regression coefficients back
```

explaination: this model can be think as a single hidden layer neural network with linear activation and randomized first layer weight: X->Z->Y

Given a not too small Z dimension, we believe to capture most information of X. The idea is inspired by [RedSVD](https://github.com/ntessore/redsvd-h)
