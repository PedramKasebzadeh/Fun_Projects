#pragma once 

typedef double Scalar;
#include<Eigen,Core>
#include<vector>
#include"Config.h"
#include "RNG.h"
#include"Optimizer.h"

class layer
{
private:
    /* data */
protected:
    typedef Eigen::Matrix<Scalar,Eugen::Dynamic,Eigen::Dynamic> Matrix;
    typedef Eigen::Matrix<Scalar,Eigen::Dynamic,1> Vector;

    const int Input_size;
    const int Output_size; 

public:
    layer(const int in_size, const int out_size);
        Input_size(in_size), Output_size(out_size){}
    virtual ~layer();

    int in_size() const {return Input_size;}
    int out_size() const {return Output_size;}

    virtual void init(const Scalar& mu,const Scalar& sigma, RNG& rng)=0;
    virtual void forward(const Matrix&prev_layer_output)=0;
    
    virtual const Matrix& output() const = 0;
    
    virtual void backprop(const Matrix& prev_layer_output,const Matrix& next_layer_output)=0;
    virtual const Matrix& backprop_data() const = 0;

    virtual std::vector<Scalar> get_patameters() const=0;
    virtual void set_parameters(const std::vector<Scalar>& param){}
    virtual std::vector<Scalar> get_derivatives() const=0;


};

layer::layer(/* args */)
{
}

layer::~layer()
{
}

