#ifndef LO2S_OTF2_COUNTERS_RAW_HPP
#define LO2S_OTF2_COUNTERS_RAW_HPP

#include "perf_tracepoint_otf2.hpp"

#include "../monitor_config.hpp"
#include "../otf2_trace.hpp"
#include "../pipe.hpp"
#include "../time/time.hpp"

#include <thread>

namespace lo2s
{
/*
 * NOTE: Encapsulates counters for ALL cpus, totally different than otf2_counters!
 */
class otf2_tracepoints
{
public:
    otf2_tracepoints(otf2_trace& trace, const monitor_config& config,
                      const perf_time_converter& time_converter);
    ~otf2_tracepoints();

public:
    void stop();

private:
    void start();
    void poll();
    void stop_all();

private:
    pipe stop_pipe_;
    std::vector<perf_tracepoint_otf2> perf_recorders_;
    std::thread thread_;
};
}

#endif // LO2S_OTF2_COUNTERS_RAW_HPP