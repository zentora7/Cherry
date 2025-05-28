#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Cherry
{
	class CHERRY_API Log
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
#define CR_CORE_TRACE(...)   ::Cherry::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CR_CORE_INFO(...)    ::Cherry::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CR_CORE_WARN(...)    ::Cherry::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CR_CORE_ERROR(...)   ::Cherry::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CR_CORE_FATAL(...)   ::Cherry::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CR_TRACE(...)        ::Cherry::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CR_INFO(...)         ::Cherry::Log::GetClientLogger()->info(__VA_ARGS__)
#define CR_WARN(...)         ::Cherry::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CR_ERROR(...)        ::Cherry::Log::GetClientLogger()->error(__VA_ARGS__)
#define CR_FATAL(...)        ::Cherry::Log::GetClientLogger()->fatal(__VA_ARGS__)