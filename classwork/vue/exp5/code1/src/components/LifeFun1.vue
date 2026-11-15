<!-- 生命周期函数 -->
<script setup>
import { ref, onBeforeMount, onMounted, onBeforeUpdate, onUpdated } from 'vue'
const msg = ref("河南科技大学软件学院！")
setTimeout(() => {
    msg.value = "欢迎学习Vue.js前端框架！"
}, 2000)

onBeforeMount(() => {
    console.log("软工2541班王艺杰")
    console.log('DOM元素渲染前', document.querySelector('.title'))
})

onMounted(() => {
    console.log('DOM元素渲染后', document.querySelector('.title'))
})

onBeforeUpdate(() => {
    console.log("数据变化之前执行！", document.querySelector('.title').innerHTML)
})

onUpdated(() => {
    console.log("数据变化之后执行！", document.querySelector('.title').innerHTML)
})
</script>

<template>
    <h1 class="title">{{msg}}</h1>
</template>