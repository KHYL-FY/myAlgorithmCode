<script setup>


import { reactive, onMounted,computed } from 'vue'
const state = reactive({
  mytext: '',
  list: []     //用于存放数据
})
onMounted(() => {   //生命周期函数onMounted,经常在该函数中获取组件所需要的数据
  fetch('/test.json')   //利用fetch从test.json中异步获取数据
    .then(res => res.json())   //获取数据成功，执行then里面的回调函数
    .then(res => {       
      state.list = res.list    //res.list即获取到的数据
      console.log(state.list)  //可以在控制台下查看获取的数据
    })
})
const computedList = computed(() => {   //定义计算属性，根据文本框输入的关键字，计算查询结果
  const newlist = state.list.filter(item => item.includes(state.mytext))
  return newlist
})
</script>

<template>
  软工2541王艺杰<br>
  请输入书籍关键字：
  <input type="text" v-model="state.mytext" />
  <p></p>
  查询结果：
  <ul>
    <li v-for="(item, index) in computedList"  :key="item">
      {{ item }}
    </li>
  </ul>
</template>