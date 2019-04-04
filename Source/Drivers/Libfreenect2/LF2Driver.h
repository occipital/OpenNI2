#ifndef LF2DRIVER_H
#define LF2DRIVER_H

#include <XnHash.h>
#include "Driver/OniDriverAPI.h"
#include "LF2Device.h"
#include <string>
#include <libfreenect2/libfreenect2.hpp>

namespace LF2 {
  class LF2Device;
  class LF2Driver :
    public oni::driver::DriverBase
  {
  public:
	LF2Driver(OniDriverServices* pDriverServices) : DriverBase(pDriverServices)	{}

    virtual OniStatus
    initialize(oni::driver::DeviceConnectedCallback, oni::driver::DeviceDisconnectedCallback, oni::driver::DeviceStateChangedCallback , void*);

    //! @note mode is no supported now.
    oni::driver::DeviceBase*
    deviceOpen (const char*,const char*);

    void
    deviceClose (oni::driver::DeviceBase*);

	virtual OniStatus 
    tryDevice(const char* uri);

    void
    shutdown ();

  protected:
    libfreenect2::Freenect2 m_f2;
	//uri -> LF2Device map
	xnl::StringsHash<LF2Device*> m_devices;
  };
}

#endif // LF2DRIVER_H
