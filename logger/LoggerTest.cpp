#include <gtest/gtest.h>
#include <fruit/fruit.h>
#include "logger.hpp"
#include "nulllogger/null_logger.cpp"

using namespace inexor::util;

fruit::Injector<Logger> injector(getNullLoggerComponent);
Logger* logger = injector.get<Logger*>();

TEST(LoggerTest, getLevel)
{
    EXPECT_EQ(logger->getLevel(), level::trace);
}

TEST(LoggerTest, setLevel)
{
    logger->setLevel(level::info);
    EXPECT_EQ(logger->getLevel(), level::info);
}

