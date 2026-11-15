
<script setup>
  import MyComC from './components/ComC.vue'
</script>
<!-- 当style拥有属性scoped时，它的CSS样式就只能作用于当前组件，
     通过该属性可以使得组件之间的样式不互相污染 -->
<style scoped>
h1 {
    background-color: cadetblue;
}
</style>

<template>
  <h1>软工2541班王艺杰——根组件App.vue</h1>
  <hr>
  <MyComA></MyComA> <!-- 使用全局注册组件MyComA -->
  <hr>
  <MyComB></MyComB> <!-- 使用全局注册组件MyComB -->
  <hr>
  <MyComC></MyComC> <!-- 使用局部注册组件MyComC -->
</template>

