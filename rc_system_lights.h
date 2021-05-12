#ifndef rc_system_lights_h_
#define rc_system_lights_h_

#include "rc_system.h"
#include "lights_system.h"

namespace rc_system {
	
	class RC_System_Lights : public RC_System {
		public:
			RC_System_Lights();
			void setup();
		
		protected:
            void out_of_period_actions(unsigned long current_ms);
			void routine(char action);
			
		private:
			LightsSystem lights;
	};
}

#endif
