// -----------------------------------------
// This is a wrapper for iSpectraSampler (iSS) with the JETSCAPE framework
// Copyright [2018] <Chun Shen>
// -----------------------------------------

#ifndef ISPECTRASAMPLERWRAPPER_H
#define ISPECTRASAMPLERWRAPPER_H

#include "SoftParticlization.h"
#include "iSS.h"

using namespace Jetscape;

class iSpectraSamplerWrapper: public SoftParticlization {
 private:
    tinyxml2::XMLElement *iSS_xml_;

    iSS *iSpectraSampler_ptr_;

 public:
    iSpectraSamplerWrapper();
    ~iSpectraSamplerWrapper();

    void InitTask();
    void Exec();
    void Clear();
    void WriteTask(weak_ptr<JetScapeWriter> w);

    void pass_hadron_list_to_JETSCAPE();
};

#endif  // ISPECTRASAMPLERWRAPPER_H