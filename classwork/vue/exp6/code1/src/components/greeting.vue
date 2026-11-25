<script setup>
  import { ref } from 'vue'
  const props=defineProps(['to'])         //声明自定义属性
  const emit = defineEmits(['toupiao'])    //声明自定义事件
  let count = ref(0)
  const btn = () => {
    if (count.value < 10) {
      count.value++;
      emit('toupiao',props.to, count.value);   //触发自定义事件时将数据传递
    }
  }
  </script>

<template>
    <button class="greeting" v-on:click="btn">{{to}}</button>
    <span v-if="count > 0"> x {{ count }}</span>
  </template>
  
  <style scoped>
  .greeting {
    border: 1px solid #ccc;
    padding: 5px;
    border-radius: 5px;
    cursor: pointer;
    outline: none;
    margin-left: 10px;
  }
  </style>