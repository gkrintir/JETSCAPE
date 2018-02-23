// Copyright @ Chun Shen
#ifndef TEST_HYDRO_FILE_JETSCAPE_H_
#define TEST_HYDRO_FILE_JETSCAPE_H_

#include "FluidDynamics.h"
#include "Hydroinfo_MUSIC.h"

#include <string>

#ifdef USE_HDF5
#include "Hydroinfo_h5.h"
#endif

using namespace Jetscape;

class HydroFile: public FluidDynamics {
    // this is wrapper class for MUSIC so that it can be used as a external
    // library for the JETSCAPE integrated framework
 private:
    tinyxml2::XMLElement *para_;

    int flag_read_in_multiple_hydro_;
    int hydro_event_idx_;

    int load_viscous_;
    int hydro_type_;

    int nskip_tau_;
    double T_c_;

#ifdef USE_HDF5
    HydroinfoH5 *hydroinfo_h5_ptr;
#endif
    Hydroinfo_MUSIC *hydroinfo_MUSIC_ptr;

 public:
     HydroFile();
     ~HydroFile();

     //! clean up hydro event
     void clean_hydro_event();

     //! This function initials hydro parameters and read in a hydro event
     void initialize_hydro(Parameter parameter_list);


     //! This function load a VISHNew hydro event
     void read_in_hydro_event(string VISH_filename, int buffer_size,
                              int load_viscous);

     //! This function load a MUSIC hydro event
     void read_in_hydro_event(string input_file, string hydro_ideal_file,
                              int nskip_tau);

     //! This function is a dummy function
     void evolve_hydro();

     //! This function provide fluid cell information at a given
     //! space-time point
     void get_hydro_info(Jetscape::real t, Jetscape::real x,
                         Jetscape::real y, Jetscape::real z,
                         std::unique_ptr<FluidCellInfo>& fluid_cell_info_ptr);

     void set_hydro_event_idx(int idx_in) {hydro_event_idx_ = idx_in;};
     int get_hydro_event_idx() {return(hydro_event_idx_);};
     void get_hypersurface(Jetscape::real T_cut, SurfaceCellInfo* surface_list_ptr) {};
};

#endif  // TEST_HYDRO_FILE_JETSCAPE_H_
