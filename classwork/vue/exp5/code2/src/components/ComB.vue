<template>
    <h1>我是组件ComB</h1>
</template>

<script setup>
</script>

<!-- 当style拥有属性scoped时，它的CSS样式就只能作用于当前组件，
     通过该属性可以使得组件之间的样式不互相污染 -->
<style scoped>
h1 {
    width: 400px;
    color: green;
    background-color: antiquewhite;
}
</style>