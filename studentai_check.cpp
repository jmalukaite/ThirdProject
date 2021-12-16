#include "studentas.h"
#include "gtest/gtest.h"

TEST(Studentas, arVeikiaEgzaminoSeteris)
{
    Studentas studentas;
    studentas.setEgzaminas(8);
    ASSERT_EQ(8, studentas.getEgzaminas());
}
