#include "extensions/object_wrapper.hpp"

namespace navagraha {
namespace extensions {

void object_wrapper::serialize(object_wrapper & obj, std::ostringstream & str)
{
    if (obj.serializer) {
        obj.serializer(str);
    }
    else {
        str.write("{}", 2);
    }
}

}
}