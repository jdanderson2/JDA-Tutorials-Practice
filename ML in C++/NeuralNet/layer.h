#ifndef __LAYER_H
#define __LAYER_H
#include "neuron.h"
#include <stdint.h>
#include <vector>

class Layer {

  public:
    int currentLayerSize;
    std::vector<Neuron *> neurons;
    std::vector<double> layerOutputs;
    Layer(int, int);
};
#endif