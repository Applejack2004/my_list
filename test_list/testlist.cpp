#include "../my_list/TList.h"

#include "gtest.h"

TEST(TList, can_create_list)
{
  ASSERT_NO_THROW(TList<int> list_project);
}


TEST(TList, can_insert_first)
{
    TList<int> list_project;
    ASSERT_NO_THROW(list_project.InsFirst(1));
    int value = list_project.Get_First();

   
  

  EXPECT_EQ(1, value);
}
TEST(TList, can_delete_first)
{
    TList<int> list_project;
   list_project.InsFirst(1);
   list_project.InsFirst(2);
   ASSERT_NO_THROW(list_project.DelFirst());
    int value = list_project.Get_First();




    EXPECT_EQ(1, value);
}
TEST(TList, cant_delete_first_in_empty_list)
{
    TList<int> list_project;

    ASSERT_ANY_THROW(list_project.DelFirst());

}
TEST(TList, can_insert_last)
{
    TList<int> list_project;
    ASSERT_NO_THROW(list_project.InsLast(1));
    list_project.InsLast(2);
    int value = list_project.Get_Last();




    EXPECT_EQ(2, value);
}
TEST(TList, can_delete_last)
{
    TList<int> list_project;
    int value;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.setPos(1);
   ASSERT_NO_THROW( list_project.DelCurr());
    value = list_project.Get_Last();




    EXPECT_EQ(1, value);
}
TEST(TList, cant_delete_last_in_empty_list)
{
    TList<int> list_project;
   
    ASSERT_ANY_THROW(list_project.DelCurr());

}
TEST(TList, can_reset_current)
{
    TList<int> list_project;


    int value1,value2;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.setPos(1);
    value1 = list_project.Get_pos();
    ASSERT_NO_THROW(list_project.Reset());
    value2 = list_project.Get_pos();
    EXPECT_NE(value1, value2);
    EXPECT_EQ(value2, 0);


}
TEST(TList, can_Go_Next)
{
    int value1;
    TList<int> list_project;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.setPos(1);
    ASSERT_NO_THROW(list_project.GoNext());
    value1 = list_project.Get_pos();
    EXPECT_EQ(value1,2);
}
TEST(TList, can_delete_list)
{
    int value1;
    TList<int> list_project;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
  
    ASSERT_NO_THROW(list_project.DelList());
   
    EXPECT_EQ(list_project.Get_pos(), -1);
    EXPECT_EQ(list_project.Get_length(), 0);
    EXPECT_EQ(list_project.Is_Empty(), 1);
}
TEST(TList, can_insert_first_by_DelCurr)
{
    TList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.setPos(0);
    list_project.InsCurr(0);
    value = list_project.Get_First();




    EXPECT_EQ(0, value);
}



