#include <gtest/gtest.h>
#include <fruit/fruit.h>
#include "logger.hpp"
#include "nulllogger/null_logger.cpp"

using namespace inexor::util;

fruit::Injector<Logger> injector(getNullLoggerComponent);
Logger* logger = injector.get<Logger*>();

TEST(LoggerTest, getLevel)
{
    EXPECT_EQ(logger->getLevel(), 0);
}

TEST(LoggerTest, setLevel)
{
    logger->setLevel(2);
    EXPECT_EQ(logger->getLevel(), 2);
}

