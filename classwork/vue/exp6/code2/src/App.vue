
<template>
  <div>
    <h1>本周任务管理—软工2541班王艺杰 </h1>
    <hr />
    <TodoInput @add="onAddNewTask"></TodoInput>  <!-- 使用TodoInput组件 -->
    <TodoList :list="tasklist"></TodoList>     <!-- 使用TodoList组件 -->
    <TodoButton @updateActive="changeActive"></TodoButton>      <!-- 使用TodoButton组件 -->
  </div>
</template>

<script setup>
import { reactive, ref ,computed} from 'vue'
import TodoList from './components/TodoList.vue' //导入并注册TodoList组件
import TodoInput from './components/TodoInput.vue' 
import TodoButton from './components/TodoButton.vue'      //导入并注册TodoButton组件

// 任务列表的数据
const todoList = reactive( [
        { id: 1, task: '周一早晨9点开会', done: false },
        { id: 2, task: '周一晚上8点聚餐', done: false },
        { id: 3, task: '准备周三上午的演讲稿', done: true },
        { id: 4, task: '准备周四上午的课件', done: false },
        { id: 5, task: '准备周五上午的实验指导', done: false },
      ]
)
const nextId=ref(6)   //下一条数据的id值
const onAddNewTask=(tname)=> {
      // 1. 向任务列表中新增任务信息
      todoList.push({
        id: nextId.value,
        task: tname,
        done: false, // 完成状态默认为 false
      });
      // 2. 让 nextId 自增+1
      nextId.value++;
}

const activeBtnIndex = ref(0)     //用来接收子组件传过来的数据，注意ref需按需导入
const changeActive = (status) => {
  console.log(status)
  activeBtnIndex.value = status   // 将子组件的状态赋值给父组件
}

// 根据激活按钮的索引值，动态计算要展示的列表数据
const tasklist=computed(()=>{
  // 对“源数据”进行 switch...case 的匹配，并返回“计算之后的结果”
  switch (activeBtnIndex.value) {

    case 0: // 全部
      return todoList;
    case 1: // 已完成
      return todoList.filter((x) => x.done);
    case 2: // 未完成
      return todoList.filter((x) => !x.done);
  }
})
</script>