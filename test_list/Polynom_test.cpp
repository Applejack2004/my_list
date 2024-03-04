#include "../my_list/TPolinom.h"
#include "../my_list/TMonom.h"
#include "gtest.h"

TEST(TMonom, can_create_monom)
{
    ASSERT_NO_THROW(TMonom Monom_project(3,123));
    TMonom Monom_project1(3, 123);
    int a=Monom_project1.Get_index();
    EXPECT_EQ(a, 123);
}
TEST(TMonom, can_compare_two_monoms)
{
    TMonom Monom_project(3, 123);
    TMonom Monom_project2(3, 123);
    TMonom Monom_project3(2, 423);
    EXPECT_TRUE(Monom_project == Monom_project2);
    EXPECT_TRUE(Monom_project != Monom_project3);
    EXPECT_TRUE(Monom_project < Monom_project3);
    EXPECT_TRUE(Monom_project3 > Monom_project2);
}

TEST(TPolinom, can_create_polinom)
{
    ASSERT_NO_THROW(TPolinom Polinom_project);
}


TEST(TPolinom, can_applied_two_polinoms)
{
    TPolinom res;
    int masres[][2] = { {5,234},{-1,123 } };
    int mas[][2] = { {2,234},{-3,231},{-2,123 } };
    int mas1[][2] = { {3,234},{3,231},{1,123 } };
    TPolinom pol_project1(mas, 3);
    TPolinom pol_project2(mas1, 3);
    TPolinom pol_project(masres, 2);

    ASSERT_NO_THROW(res = pol_project1 + pol_project2);



    EXPECT_TRUE(pol_project== res);
}
TEST(TPolinom, can_applied_one_polinom_to_second)
{
   // TPolinom res;
    int masres[][2] = { {5,234},{-1,123 } };
    int mas[][2] = { {2,234},{-3,231},{-2,123 } };
    int mas1[][2] = { {3,234},{3,231},{1,123 } };
    TPolinom pol_project1(mas, 3);
    TPolinom pol_project2(mas1, 3);
    TPolinom pol_project(masres, 2);

    ASSERT_NO_THROW(pol_project1+= pol_project2);



    EXPECT_TRUE(pol_project1== pol_project);
}
TEST(TPolinom, can_subtract_two_polinoms)
{
    TPolinom res;
    int masres[][2] = { {-6,231},{1,123 } };
    int mas[][2] = { {5,234},{-3,231},{2,123 } };
    int mas1[][2] = { {5,234},{3,231},{1,123 } };
    TPolinom pol_project1(mas, 3);
    TPolinom pol_project2(mas1, 3);
    TPolinom pol_project(masres, 2);

    ASSERT_NO_THROW(res = pol_project1 - pol_project2);



    EXPECT_TRUE(pol_project == res);
}
TEST(TPolinom, can_applied_one_monnom_in_polynom)
{
   
    TMonom mon(3, 457);
    int masres[][2] = { {3, 457},{2,234},{-3,231},{-2,123}};
    int mas[][2] = { {2,234},{-3,231},{-2,123 } };
    TPolinom res(masres,4);
    TPolinom pol_project1(mas, 3);
   

    ASSERT_NO_THROW(pol_project1.AddMonom(mon));



    EXPECT_TRUE(pol_project1 == res);
}
TEST(TPolinom, can_multiply_two_polinoms)
{
    TPolinom res;
    int masres[][2] = { {25,468},{-9,462 },{15,357},{3,354},{2,246}};
    int mas[][2] = { {5,234},{-3,231},{2,123 } };
    int mas1[][2] = { {5,234},{3,231},{1,123 } };
    TPolinom pol_project1(mas, 3);
    TPolinom pol_project2(mas1, 3);
    TPolinom pol_project(masres, 5);

    ASSERT_NO_THROW(res = pol_project1 * pol_project2);



    EXPECT_TRUE(pol_project == res);
}
TEST(TPolinom, can_multiply_polinom_on_const)
{
    TPolinom res;
   
    int mas[][2] = { {5,234},{-3,231},{2,123 } };
    int mas1[][2] = { {25,234},{15,231},{5,123 } };
    TPolinom pol_project1(mas, 3);
    TPolinom pol_project2(mas1, 3);


    ASSERT_NO_THROW(res = pol_project1 * 5);



    EXPECT_TRUE(pol_project2 == res);
}