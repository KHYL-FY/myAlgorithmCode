<script setup>
import { reactive, ref } from 'vue';
const list = reactive(["学习", "吃饭", "购物"])
const inputValue = ref("")
// 添加
const add = () => {
    list.push(inputValue.value)
    inputValue.value= ""
}
// 删除
const remove = (x) => {
    list.splice(x, 1)
}
// 清除
const clear = () => {
    list.splice(0)
}
</script>

<template>
<h1>软工2541班王艺杰</h1>
   <h2>迷你记事本</h2>
    <div id="box">
      <!-- 写区域 -->
      <div class="write">
        <input type="text"  placeholder="请输入任务......"  v-model ="inputValue"  @keydown.enter = "add"  @keydown.esc="inputValue = ''">
      </div>
      <!-- 显示区域 -->
      <ul>
         <li  v-for="(item, index) in list"  :key="item"> {{ index + 1 + ": " }}{{ item }}          
<img src="../assets/images/delect.png"   @click="remove">
        </li>
      </ul>
      <!-- 统计区域 -->
      <div class="count">
         <span class="left"   v-text="'共 '+ list.length + ' 项'" v-show="list.length"></span>
         <span class="right"  @click=" clear"  v-show="list.length">清空</span>
      </div>     
 </div>
</template>

<style scoped>
ul,
li {
    padding: 0;
    margin: 0;
}

#box {
    width: 300px;
    margin: 20px auto 0 auto;
    border:3px solid #ccc;
    background-color: #eee;
    border-radius: 5px;
}

h1,h2 {
    text-align: center;
    margin-bottom: 10px;
    color: red;
}

div.write>input {
    height: 35px;
    width: 288px;
    border: none;
    border-bottom: 1px solid #ccc;
    padding-left: 10px;
    font-size: 20px;
    font-style: italic;
    outline: none;
}

ul {
    list-style: none;
    background-color: #fff;
    padding-left: 10px;
    padding-right: 10px;
}

ul>li {
    line-height: 38px;
    color: #000;
    font-size: 20px;
    border-bottom: 1px solid #ccc;
    position: relative;
}
ul>li:last-child{
    border-bottom: none;
}
ul>li>img {
    width: 24px;
    position: absolute;
    right: 0;
    top: 9px;
    display: none;
    cursor: pointer;
}
ul>li:hover>img {
    display: block;
}
div.count {
    height: 20px;
    color: #000;
    font-size: 12px;
    padding: 8px 10px 0 10px;
    position: relative;
}
div.count>span.right {
    float: right;
    cursor: pointer;
}
</style>