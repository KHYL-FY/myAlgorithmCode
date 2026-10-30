<script setup>
import { ref } from 'vue'
const num = ref(0)
const sub = () => {
    if(num.value >- 10) num.value--
    else alert("不要减了，已经最小了！")
}
const add = () => {
    if(num.value <10) num.value++
    else alert("不要加了，已经最大了！")
}
</script>

<template>
    <h1>软工2541班王艺杰</h1>
    <button type="button" @click="sub">-</button>
    <span v-text = num></span>
    <button type="button" @click="add">+</button>
</template>

<style scoped>
button {
    width: 70px;
    height: 40px;
    color: red;
    font-size: 30px;
    line-height: 30px;
    float: left;
}
span {
    display: block;
    width: 158px;
    height: 38px;
    border: 1px solid red;
    float: left;
    font-size: 40px;
    text-align: center;
    line-height: 38px;
}
</style>
