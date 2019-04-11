#include	"wyreg.hpp"
#include	<iostream>
#include	<fstream>
#include	<cstdlib>
using	namespace	std;
using	namespace	Eigen;

bool	load_matrix(const	char	*F,	vector<float>	&M,	unsigned	&R,	unsigned	&C) {
	ifstream	fi(F);
	if(!fi) {	cerr<<"fail to open "<<F<<'\n';	return	false;	}
	string	buf;	R=C=0;
	while(getline(fi,buf))	if(buf.size()) {
		char	*p=(char*)buf.data(),	*q;
		for(;;) {	
			q=p;	float	x=strtod(p,	&p);
			if(p!=q)	M.push_back(x);	else	break;
		}
		R++;
	}
	fi.close();
	if(M.size()%R) {	cerr<<"unequal column\t"<<F<<'\n';	return	false;	}
	C=M.size()/R;	cerr<<F<<'\t'<<R<<'*'<<C<<'\n';
	return	true;
}

int	main(int	ac,	char	**av){
	if(ac!=4){	cerr<<"example ymat xmat dims\n";	return	0;	}
	MatrixXf	ymat,	xmat;
	{
		vector<float>	temp;	unsigned	r,	c;
		if(!load_matrix(av[1],	temp,	r,	c))	return	0;
		ymat.resize(r,c);
		for(size_t	i=0;	i<r;	i++)	for(size_t	j=0;	j<c;	j++)	ymat(i,j)=temp[i*c+j];
		if(!load_matrix(av[2],	temp,	r,	c))	return	0;
		xmat.resize(r,c);
		for(size_t	i=0;	i<r;	i++)	for(size_t	j=0;	j<c;	j++)	xmat(i,j)=temp[i*c+j];
		if(ymat.rows()!=xmat.rows())	return	0;
	}	
	LLT<MatrixXf>	llt(xmat.transpose()*xmat);
	MatrixXf	beta=llt.solve(xmat.transpose()*ymat),	beta1;
	wyreg(ymat,xmat,beta1,atoi(av[3]),time(NULL));	cout.precision(4);	cout.setf(ios::fixed);
	for(int	i=0;	i<beta.rows();	i++){
		for(int	j=0;	j<beta.cols();	j++)	cout<<beta(i,j)<<"\t"<<beta1(i,j)<<"\t|";
		cout<<'\n';
	}
	return	0;
}
