#include "util/packed_vector.hpp"
#include "util/typedefs.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>

BOOST_AUTO_TEST_SUITE(packed_vector_test)

using namespace osrm;
using namespace osrm::util;

// Verify that the packed vector behaves as expected
BOOST_AUTO_TEST_CASE(insert_and_retrieve_packed_test)
{
    PackedVector packed_ids;
    std::vector<OSMNodeID> original_ids;

    const constexpr std::size_t num_test_cases = 399;

    for (std::size_t i = 0; i < num_test_cases; i++)
    {
        OSMNodeID r = static_cast<OSMNodeID>(rand() % 2147483647); // max 33-bit uint

        packed_ids.insert(r);
        original_ids.push_back(r);
    }

    for (std::size_t i = 0; i < num_test_cases; i++)
    {
        BOOST_CHECK_EQUAL(original_ids.at(i), packed_ids.retrieve(i));
    }
}

BOOST_AUTO_TEST_SUITE_END()
