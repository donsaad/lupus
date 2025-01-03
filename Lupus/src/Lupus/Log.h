#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
//#include "spdlog/fmt/ostr.h"

namespace Lupus
{
	class LUPUS_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define LP_CORE_TRACE(...)     ::Lupus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LP_CORE_INFO(...)      ::Lupus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LP_CORE_WARN(...)      ::Lupus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LP_CORE_ERROR(...)     ::Lupus::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define LP_CORE_FATAL(...)     ::Lupus::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LP_TRACE(...)          ::Lupus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LP_INFO(...)           ::Lupus::Log::GetClientLogger()->info(__VA_ARGS__)
#define LP_WARN(...)           ::Lupus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LP_ERROR(...)          ::Lupus::Log::GetClientLogger()->error(__VA_ARGS__)
//#define LP_FATAL(...)          ::Lupus::Log::GetClientLogger()->fatal(__VA_ARGS__)