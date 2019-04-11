#ifndef wyreg_20190411
#define wyreg_20190411
#include	<Eigen/Eigen>
#include	"wyhash.h"
/*
	Y=XB	the conventional regression setting
	W=Guasian	random projection matrix
	x=XW	project X to low dimension
	Y=xb	solve low dimension regression
	Y=XWb => B=Wb
*/

//TODO	use template to produce generic function
void	wyreg(const	Eigen::MatrixXf&	ymat,	const	Eigen::MatrixXf&	xmat,	Eigen::MatrixXf&	beta,	unsigned	dims,	unsigned long long	seed){
	Eigen::MatrixXf	wmat(xmat.cols(),	dims);
	for(unsigned	i=0;	i<wmat.cols();	i++)	for(unsigned	j=0;	j<wmat.rows();	j++)	wmat(j,i)=wyrandgau(&seed);
	Eigen::MatrixXf	xmat1=xmat*wmat;
	Eigen::LLT<Eigen::MatrixXf>	llt(xmat1.transpose()*xmat1);
	Eigen::MatrixXf	beta1=llt.solve(xmat1.transpose()*ymat);
	beta=wmat*beta1;
}
#endif
