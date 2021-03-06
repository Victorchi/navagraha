#ifndef _NAVAGRAHA_KUBEENT_ROLLING_UPDATE_STATEFUL_SET_STRATEGY_H
#define _NAVAGRAHA_KUBEENT_ROLLING_UPDATE_STATEFUL_SET_STRATEGY_H

#include "extensions/field.hpp"
#include "extensions/serializer_helper.hpp"
#include "kubeent/serializable.hpp"

namespace navagraha {
namespace kubeent {

extern char ROLLING_UPDATE_STATEFUL_SET_STRATEGY_PARTITION[];

class rolling_update_stateful_set_strategy : public serializable<rolling_update_stateful_set_strategy> {
public:
    extensions::field<int, ROLLING_UPDATE_STATEFUL_SET_STRATEGY_PARTITION> partition;

    void bind(extensions::serializer_helper & helper);
};

}
}

#endif
