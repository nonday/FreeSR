// 
// Copyright (C) 2018, Xulg. All rights reserved.
// 
// xulg <xulg.ai@qq.com>
// 

#ifndef COMMON_H_
#define COMMON_H_

#include <Eigen/Core>


#define PI 3.14159265359


typedef struct Gmm_ {
  Eigen::MatrixXd mu;
  Eigen::MatrixXd sigma;
  Eigen::VectorXd w;
} Gmm;

typedef struct Plda_ {
	Eigen::MatrixXd phi;
	Eigen::MatrixXd sigma;
	Eigen::MatrixXd w;
	Eigen::MatrixXd m;
} Plda;

#endif  // COMMON_H_
