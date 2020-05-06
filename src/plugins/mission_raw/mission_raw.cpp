// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/mission_raw/mission_raw.proto)

#include <iomanip>

#include "mission_raw_impl.h"
#include "plugins/mission_raw/mission_raw.h"

namespace mavsdk {

using MissionProgress = MissionRaw::MissionProgress;
using MissionItem = MissionRaw::MissionItem;

MissionRaw::MissionRaw(System& system) : PluginBase(), _impl{new MissionRawImpl(system)} {}

MissionRaw::~MissionRaw() {}

void MissionRaw::upload_mission_async(
    std::vector<MissionItem> mission_items, const result_callback_t callback)
{
    _impl->upload_mission_async(mission_items, callback);
}

MissionRaw::Result MissionRaw::upload_mission(std::vector<MissionItem> mission_items) const
{
    return _impl->upload_mission(mission_items);
}

MissionRaw::Result MissionRaw::cancel_mission_upload() const
{
    return _impl->cancel_mission_upload();
}

void MissionRaw::download_mission_async(const download_mission_callback_t callback)
{
    _impl->download_mission_async(callback);
}

std::pair<MissionRaw::Result, std::vector<MissionRaw::MissionItem>>
MissionRaw::download_mission() const
{
    return _impl->download_mission();
}

MissionRaw::Result MissionRaw::cancel_mission_download() const
{
    return _impl->cancel_mission_download();
}

void MissionRaw::start_mission_async(const result_callback_t callback)
{
    _impl->start_mission_async(callback);
}

MissionRaw::Result MissionRaw::start_mission() const
{
    return _impl->start_mission();
}

void MissionRaw::pause_mission_async(const result_callback_t callback)
{
    _impl->pause_mission_async(callback);
}

MissionRaw::Result MissionRaw::pause_mission() const
{
    return _impl->pause_mission();
}

void MissionRaw::clear_mission_async(const result_callback_t callback)
{
    _impl->clear_mission_async(callback);
}

MissionRaw::Result MissionRaw::clear_mission() const
{
    return _impl->clear_mission();
}

void MissionRaw::set_current_mission_item_async(int32_t index, const result_callback_t callback)
{
    _impl->set_current_mission_item_async(index, callback);
}

MissionRaw::Result MissionRaw::set_current_mission_item(int32_t index) const
{
    return _impl->set_current_mission_item(index);
}

void MissionRaw::subscribe_mission_progress(mission_progress_callback_t callback)
{
    _impl->mission_progress_async(callback);
}

MissionRaw::MissionProgress MissionRaw::mission_progress() const
{
    return _impl->mission_progress();
}

void MissionRaw::subscribe_mission_changed(mission_changed_callback_t callback)
{
    _impl->mission_changed_async(callback);
}

bool operator==(const MissionRaw::MissionProgress& lhs, const MissionRaw::MissionProgress& rhs)
{
    return (rhs.current == lhs.current) && (rhs.total == lhs.total);
}

std::ostream& operator<<(std::ostream& str, MissionRaw::MissionProgress const& mission_progress)
{
    str << std::setprecision(15);
    str << "mission_progress:" << '\n' << "{\n";
    str << "    current: " << mission_progress.current << '\n';
    str << "    total: " << mission_progress.total << '\n';
    str << '}';
    return str;
}

bool operator==(const MissionRaw::MissionItem& lhs, const MissionRaw::MissionItem& rhs)
{
    return (rhs.seq == lhs.seq) && (rhs.frame == lhs.frame) && (rhs.command == lhs.command) &&
           (rhs.current == lhs.current) && (rhs.autocontinue == lhs.autocontinue) &&
           ((std::isnan(rhs.param1) && std::isnan(lhs.param1)) || rhs.param1 == lhs.param1) &&
           ((std::isnan(rhs.param2) && std::isnan(lhs.param2)) || rhs.param2 == lhs.param2) &&
           ((std::isnan(rhs.param3) && std::isnan(lhs.param3)) || rhs.param3 == lhs.param3) &&
           ((std::isnan(rhs.param4) && std::isnan(lhs.param4)) || rhs.param4 == lhs.param4) &&
           (rhs.x == lhs.x) && (rhs.y == lhs.y) &&
           ((std::isnan(rhs.z) && std::isnan(lhs.z)) || rhs.z == lhs.z) &&
           (rhs.mission_type == lhs.mission_type);
}

std::ostream& operator<<(std::ostream& str, MissionRaw::MissionItem const& mission_item)
{
    str << std::setprecision(15);
    str << "mission_item:" << '\n' << "{\n";
    str << "    seq: " << mission_item.seq << '\n';
    str << "    frame: " << mission_item.frame << '\n';
    str << "    command: " << mission_item.command << '\n';
    str << "    current: " << mission_item.current << '\n';
    str << "    autocontinue: " << mission_item.autocontinue << '\n';
    str << "    param1: " << mission_item.param1 << '\n';
    str << "    param2: " << mission_item.param2 << '\n';
    str << "    param3: " << mission_item.param3 << '\n';
    str << "    param4: " << mission_item.param4 << '\n';
    str << "    x: " << mission_item.x << '\n';
    str << "    y: " << mission_item.y << '\n';
    str << "    z: " << mission_item.z << '\n';
    str << "    mission_type: " << mission_item.mission_type << '\n';
    str << '}';
    return str;
}

const char* MissionRaw::result_str(MissionRaw::Result result)
{
    switch (result) {
        case MissionRaw::Result::Unknown:
            return "Unknown error";
        case MissionRaw::Result::Success:
            return "Request succeeded";
        case MissionRaw::Result::Error:
            return "Error";
        case MissionRaw::Result::TooManyMissionItems:
            return "Too many mission items in the mission";
        case MissionRaw::Result::Busy:
            return "Vehicle is busy";
        case MissionRaw::Result::Timeout:
            return "Request timed out";
        case MissionRaw::Result::InvalidArgument:
            return "Invalid argument";
        case MissionRaw::Result::Unsupported:
            return "Mission downloaded from the system is not supported";
        case MissionRaw::Result::NoMissionAvailable:
            return "No mission available on the system";
        case MissionRaw::Result::TransferCancelled:
            return "Mission transfer (upload or download) has been cancelled";
        default:
            return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, MissionRaw::Result const& result)
{
    switch (result) {
        case MissionRaw::Result::Unknown:
            return str << "Result Unknown";
        case MissionRaw::Result::Success:
            return str << "Result Success";
        case MissionRaw::Result::Error:
            return str << "Result Error";
        case MissionRaw::Result::TooManyMissionItems:
            return str << "Result Too Many Mission Items";
        case MissionRaw::Result::Busy:
            return str << "Result Busy";
        case MissionRaw::Result::Timeout:
            return str << "Result Timeout";
        case MissionRaw::Result::InvalidArgument:
            return str << "Result Invalid Argument";
        case MissionRaw::Result::Unsupported:
            return str << "Result Unsupported";
        case MissionRaw::Result::NoMissionAvailable:
            return str << "Result No Mission Available";
        case MissionRaw::Result::TransferCancelled:
            return str << "Result Transfer Cancelled";
        default:
            return str << "Unknown";
    }
}

} // namespace mavsdk