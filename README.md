# DNN
A simple open-source Deep Neural Network implementation write in c++;


# USE
It has a simple use.
First you put the number of input , hidden and output nodes of the layers and the learning rate. 
EX:
NN::NeuralNetwork brain(2,2,1,0.2); // now it has just an hidden layer 

And after that you could use the function Backpropagation(matrix input, matrix target) to train the neural network and the function named feedforward(matrix input) for making a guess.
In main.cpp you have an example where the NN is trained and making right predictions for the xor problem.
